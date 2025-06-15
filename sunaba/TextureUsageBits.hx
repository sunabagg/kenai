package sunaba;

enum abstract TextureUsageBits(Int) from Int to Int {
	var samplingBit = 1;
	var colorAttachmentBit = 2;
	var depthStencilAttachmentBit = 4;
	var storageBit = 8;
	var storageAtomicBit = 16;
	var cpuReadBit = 32;
	var canUpdateBit = 64;
	var canCopyFromBit = 128;
	var canCopyToBit = 256;
	var inputAttachmentBit = 512;
}
