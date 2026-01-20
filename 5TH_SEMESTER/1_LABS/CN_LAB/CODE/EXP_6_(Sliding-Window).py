def sliding_window(total, window):
    for start in range(0, total, window):
        frames = list(range(start, min(start + window, total)))
        print("Frames sent:", *frames)
        print("Acknowledgments received for frames:", *frames, "\n")
    print("All frames have been sent and acknowledged.")

# Run
total = int(input("Enter the total number of frames: "))
window = int(input("Enter the window size: "))
sliding_window(total, window)






'''Enter the total number of frames: 10
Enter the window size: 3
Frames sent: 0 1 2
Acknowledgments received for frames: 0 1 2 

Frames sent: 3 4 5
Acknowledgments received for frames: 3 4 5 

Frames sent: 6 7 8
Acknowledgments received for frames: 6 7 8 

Frames sent: 9
Acknowledgments received for frames: 9 

All frames have been sent and acknowledged.'''
