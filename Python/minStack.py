class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.arr = []
        self.min_values = []

    def push(self, x: int) -> None:
        self.arr.append(x)

        if not self.min_values or x <= self.min_values[-1]:
            self.min_values.append(x)

    def pop(self) -> None:
        self.arr.pop()

    def top(self) -> int:
        return self.arr[-1]

    def getMin(self) -> int:
        return self.min_values[-1]


# Your MinStack object will be instantiated and called as such:
obj = MinStack()
obj.push(-2)
obj.push(0)
obj.push(-3)
param_1 = obj.getMin()
obj.pop()
param_2 = obj.top()
param_3 = obj.getMin()
