from collections import defaultdict

x = ["eat", "tea", "tan", "ate", "nat", "bat"]


def main():
    count = []

    ans = defaultdict(list)

    for s in x:
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1
        ans[tuple(count)].append(s)
    return ans.values()


if __name__ == "__main__":
    print(main())
