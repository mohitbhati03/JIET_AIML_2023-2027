BUCKET_SIZE = 30
OUTGOING_RATE = 3

n = int(input("Enter number of packets: "))
bucket = 0

for t in range(1, n+1):
    incoming = int(input(f"Time {t}, incoming packets: "))
    if incoming + bucket > BUCKET_SIZE:
        print(f"Overflow! Dropped {(incoming + bucket) - BUCKET_SIZE} packets")
        bucket = BUCKET_SIZE
    else:
        bucket += incoming

    print(f"In bucket: {bucket}")
    bucket = max(0, bucket - OUTGOING_RATE)
    print(f"After sending {OUTGOING_RATE}, remaining: {bucket}")

while bucket > 0:
    print(f"After sending {OUTGOING_RATE}, remaining: {bucket}")
    bucket = max(0, bucket - OUTGOING_RATE)

print("Bucket empty")
