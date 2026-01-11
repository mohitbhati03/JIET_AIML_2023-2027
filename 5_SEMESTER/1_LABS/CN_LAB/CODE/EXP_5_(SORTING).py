import random

SIZE = 3

def main():
    msg = input("Enter message: ")
    frames = [(msg[i:i+SIZE], i//SIZE) for i in range(0, len(msg), SIZE)]
    print("\nAssigned:", [f"{s}:{t}" for t,s in frames])
    random.shuffle(frames)
    print("\nShuffled:", [f"{s}:{t}" for t,s in frames])
    frames.sort(key=lambda x: x[1])
    print("\nSorted:", "".join(t for t,_ in frames))

if __name__ == "__main__":
    main()
