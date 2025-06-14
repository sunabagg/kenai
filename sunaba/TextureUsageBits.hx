package sunaba;

enum abstract TextureUsageBits(Int) {
	var SamplingBit = 1;
	var ColorAttachmentBit = 2;
	var DepthStencilAttachmentBit = 4;
	var StorageBit = 8;
	var StorageAtomicBit = 16;
	var CpuReadBit = 32;
	var CanUpdateBit = 64;
	var CanCopyFromBit = 128;
	var CanCopyToBit = 256;
	var InputAttachmentBit = 512;
}
