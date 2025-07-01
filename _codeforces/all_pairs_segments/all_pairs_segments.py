def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    idx = 0
    t = int(data[idx])
    idx += 1
    results = []

    for i in range(t):
        n, q = map(int, data[idx].split())
        idx += 1
        arr = list(map(int, data[idx].split()))
        idx += 1
        queries = list(map(int, data[idx].split()))
        idx += 1
        segment_count = {}
        for j in range(n - 1):
            num_segments = (j + 1) * (n - (j + 1))
            segment_count[num_segments] = segment_count.get(num_segments, 0) + (arr[j + 1] - arr[j])
        for j in range(n):
            num_segments = (j + 1) * (n - j)
            segment_count[num_segments] = segment_count.get(num_segments, 0) + 1
        result = []
        for cur_q in queries:
            result.append(str(segment_count.get(cur_q, 0)))
        
        results.append(' '.join(result))

    sys.stdout.write('\n'.join(results) + '\n')


if __name__ == "__main__":
    main()
