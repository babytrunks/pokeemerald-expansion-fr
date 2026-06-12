from PIL import Image
import sys

def reflow_vertical_to_horizontal(path, frame_width=16, frame_height=32):
    src = Image.open(path)
    num_frames = src.height // frame_height
    dst = Image.new(src.mode, (frame_width * num_frames, frame_height))
    if src.mode == 'P':
        dst.putpalette(src.getpalette())
    for i in range(num_frames):
        frame = src.crop((0, i * frame_height, frame_width, (i + 1) * frame_height))
        dst.paste(frame, (i * frame_width, 0))
    dst.save(path)
    print(f"Saved {path} as {dst.size}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python sprite_reflow.py <image.png> [frame_width] [frame_height]")
        sys.exit(1)
    path = sys.argv[1]
    fw = int(sys.argv[2]) if len(sys.argv) > 2 else 16
    fh = int(sys.argv[3]) if len(sys.argv) > 3 else 32
    reflow_vertical_to_horizontal(path, fw, fh)
