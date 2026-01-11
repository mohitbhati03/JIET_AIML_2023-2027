import random

def go_back_n(total, window):
    ack = 0
    while ack < total:
        print("\nSending frames:")
        frames = list(range(ack, min(ack + window, total)))
        for f in frames:
            print(f"Frame {f} sent.")
        error = random.randint(0, len(frames) - 1)
        print(f"Acknowledgment received for frames up to {ack + error}.")
        ack += error + 1
        if error < len(frames) - 1 and ack < total:
            print(f"Error in frame {ack + error}. Resending from frame {ack}.")
    print("\nAll frames have been sent and acknowledged successfully.")

# Run
total = int(input("Enter total number of frames to send: "))
window = int(input("Enter the window size: "))
go_back_n(total, window)
