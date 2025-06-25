import lucidfx.core.Variant;
import lucidfx.Error;
import lucidfx.core.RegExMatch;
import lucidfx.core.RegEx;
import lua.Table;

@:coreApi
class EReg {
    private var pattern: String;
    private var options: String;
    private var regex: RegEx;
    private var lastMatch: RegExMatch;
    private var lastInput: String;

    /**
		Creates a new regular expression with pattern `r` and modifiers `opt`.

		This is equivalent to the shorthand syntax `~/r/opt`

		If `r` or `opt` are null, the result is unspecified.
	**/
	public function new(r:String, opt:String) {
        pattern = r;
        options = opt;
        regex = new RegEx();
        if (opt == null || opt == "") {
            opt = "g"; // Default to global matching if no options are provided
        }

        if (StringTools.contains(opt, "g")) {
            opt = StringTools.replace(opt, "g", ""); // Remove global modifier for Godot compatibility
        }

        var godotPattern = r;
        if (StringTools.contains(opt, "i")) {
            godotPattern = "(?i)" + r; // Add case-insensitive modifier if not present
        }

        if (StringTools.contains(opt, "m")) {
            godotPattern = "(?m)" + r; // Add multiline modifier if not present
        }

        var error = regex.compile(godotPattern, true);
        if (error != Error.ok) {
            throw "Failed to compile regex pattern: " + r;
        }
    }

	/**
		Tells if `this` regular expression matches String `s`.

		This method modifies the internal state.

		If `s` is `null`, the result is unspecified.
	**/
	public function match(s:String):Bool {
        lastInput = s;
		lastMatch = regex.search(s, 0, -1);
        if (lastMatch == null) {
            return false; // No match found or invalid match
        }
        else {
            return lastMatch.isNull() == false; // Check if the match is valid
        }
	}

	/**
		Returns the matched sub-group `n` of `this` EReg.

		This method should only be called after `this.match` or
		`this.matchSub`, and then operates on the String of that operation.

		The index `n` corresponds to the n-th set of parentheses in the pattern
		of `this` EReg. If no such sub-group exists, the result is unspecified.

		If `n` equals 0, the whole matched substring is returned.
	**/
	public function matched(n:Int):String {
		if (lastMatch == null || lastMatch.isNull()) {
            return ""; // No match found
        }

        var nVariant: Variant = n;
        return lastMatch.getString(nVariant);
	}

	/**
		Returns the part to the left of the last matched substring.

		If the most recent call to `this.match` or `this.matchSub` did not
		match anything, the result is unspecified.

		If the global g modifier was in place for the matching, only the
		substring to the left of the leftmost match is returned.

		The result does not include the matched part.
	**/
	public function matchedLeft():String {
		if (lastMatch == null || lastMatch.isNull()) {
            return ""; // No match found
        }
        return lastInput.substr(0, lastMatch.getStart(0));
	}

	/**
		Returns the part to the right of the last matched substring.

		If the most recent call to `this.match` or `this.matchSub` did not
		match anything, the result is unspecified.

		If the global g modifier was in place for the matching, only the
		substring to the right of the leftmost match is returned.

		The result does not include the matched part.
	**/
	public function matchedRight():String {
		if (lastMatch == null || lastMatch.isNull()) {
            return ""; // No match found
        }
        var endPos = lastMatch.getEnd(0);
        return lastInput.substr(endPos);
	}

	/**
		Returns the position and length of the last matched substring, within
		the String which was last used as argument to `this.match` or
		`this.matchSub`.

		If the most recent call to `this.match` or `this.matchSub` did not
		match anything, the result is unspecified.

		If the global g modifier was in place for the matching, the position and
		length of the leftmost substring is returned.
	**/
	public function matchedPos():{pos:Int, len:Int} {
		if (lastMatch == null || lastMatch.isNull()) {
            return { pos: -1, len: 0 }; // No match found
        }
        var start = lastMatch.getStart(0);
        var end = lastMatch.getEnd(0) - start;
        return { pos: start, len: end - start };
	}

	/**
		Tells if `this` regular expression matches a substring of String `s`.

		This function expects `pos` and `len` to describe a valid substring of
		`s`, or else the result is unspecified. To get more robust behavior,
		`this.match(s.substr(pos,len))` can be used instead.

		This method modifies the internal state.

		If `s` is null, the result is unspecified.
	**/
	public function matchSub(s:String, pos:Int, len:Int = -1):Bool {
		lastInput = s;
        lastMatch = regex.search(s, pos, -1);
        if (lastMatch == null) {
            return false; // No match found or invalid match
        }
        return lastMatch.isNull() == false; // Check if the match is valid
	}

	/**
		Splits String `s` at all substrings `this` EReg matches.

		If a match is found at the start of `s`, the result contains a leading
		empty String "" entry.

		If a match is found at the end of `s`, the result contains a trailing
		empty String "" entry.

		If two matching substrings appear next to each other, the result
		contains the empty String `""` between them.

		By default, this method splits `s` into two parts at the first matched
		substring. If the global g modifier is in place, `s` is split at each
		matched substring.

		If `s` is null, the result is unspecified.
	**/
	public function split(s:String):Array<String> {
		var result:Array<String> = [];
        var lastIndex = 0;
        var searchAllTable = regex.searchAll(s, 0, -1);
        var matches:Array<RegExMatch> = Table.toArray(searchAllTable);
        for (match in matches) {
            if (match.isNull()) continue; // Skip invalid matches
            var start = match.getStart(0);
            result.push(s.substr(lastIndex, start - lastIndex));
            lastIndex = match.getEnd(0);
        }
        result.push(s.substr(lastIndex)); // Add the remaining part after the last match
		return result;
	}

	/**
		Replaces the first substring of `s` which `this` EReg matches with `by`.

		If `this` EReg does not match any substring, the result is `s`.

		By default, this method replaces only the first matched substring. If
		the global g modifier is in place, all matched substrings are replaced.

		If `by` contains `$1` to `$9`, the digit corresponds to number of a
		matched sub-group and its value is used instead. If no such sub-group
		exists, the replacement is unspecified. The string `$$` becomes `$`.

		If `s` or `by` are null, the result is unspecified.
	**/
	public function replace(s:String, by:String):String {
		return regex.sub(s, by, false, 0, -1);
	}

	/**
		Calls the function `f` for the substring of `s` which `this` EReg matches
		and replaces that substring with the result of `f` call.

		The `f` function takes `this` EReg object as its first argument and should
		return a replacement string for the substring matched.

		If `this` EReg does not match any substring, the result is `s`.

		By default, this method replaces only the first matched substring. If
		the global g modifier is in place, all matched substrings are replaced.

		If `s` or `f` are null, the result is unspecified.
	**/
	public function map(s:String, f:EReg->String):String {
		var result:String = "";
        var lastIndex = 0;
        var searchAllVector = regex.searchAll(s, 0, -1);
        var matches:Array<RegExMatch> = searchAllVector.toArray();

        for (match in matches) {
            var start = match.getStart(0);
            var end = match.getEnd(0);
            result += s.substr(lastIndex, start - lastIndex); // Add the part before the

            result += f(this); // Call the function with the EReg object
            lastIndex = end; // Update the last index to the end of the match
        }

        result += s.substr(lastIndex); // Add the remaining part after the last match
        return result;
	}

	/**
		Escape the string `s` for use as a part of regular expression.

		If `s` is null, the result is unspecified.
	**/
	public static function escape(s:String):String {
		var specials = ['\\', '.', '+', '*', '?', '^', '$', '(', ')', '[', ']', '{', '}', '|'];
        var text = s;
        for (special in specials) {
            text = StringTools.replace(text, special, '\\' + special);
        }
        return text;
	}
}