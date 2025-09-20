from __future__ import annotations


class Vector:
    def __init__(self, dimension: int = 2):
        self._dimension = dimension
        self.points = [0 for i in range(dimension)]

    @property
    def get_dimension(self) -> int:
        return self._dimension

    def set_coords(self) -> None:
        print(f'Enter lenghts of vector of {self._dimension} in a row')
        lenghts = [int(coord) for coord in input().split()]
        if len(lenghts) != self._dimension:
            raise TypeError("Incorrect dimension")
        self.points = lenghts

    def __str__(self) -> str:
        return ' '.join(str(i) for i in self.points)

    def __abs__(self) -> float:
        amount = sum([lenght ** 2 for lenght in self.points]) ** 0.5
        return amount

    def __neg__(self) -> Vector:
        vector = Vector(dimension=self._dimension)
        vector.points = [-self.points[i] for i in range(self._dimension)]
        return vector

    def __pos__(self) -> Vector:
        return self

    def __add__(self, other: Vector) -> "Vector":
        if not isinstance(other, Vector):
            raise TypeError("Can add only Vectors")
        if self._dimension != other._dimension:
            raise ValueError("Dimension of vectors must equals")

        vector = Vector(dimension=self._dimension)
        for coord in range(self._dimension):
            vector.points[coord] += self.points[coord]
            vector.points[coord] += other.points[coord]

        return vector

    def __sub__(self, other: Vector) -> "Vector":
        if not isinstance(other, Vector):
            raise TypeError("Can subtract only Vectors")
        if self._dimension != other._dimension:
            raise ValueError("Dimension of vectors must equals")

        vector = Vector(dimension=self._dimension)
        for coord in range(self._dimension):
            vector.points[coord] += self.points[coord]
            vector.points[coord] -= other.points[coord]

        return vector

    def __mul__(self, other: Vector) -> int:
        if not isinstance(other, Vector):
            raise TypeError("Can multiply only Vectors")
        if self._dimension != other._dimension:
            raise ValueError("Dimension of vectors must equals")

        amount = sum([self.points[coord] * other.points[coord] for coord in range(self._dimension)])
        return amount


A = Vector(dimension=2)
A.set_coords()

B = Vector(dimension=2)
B.set_coords()

print('-' * 16)
print(A + B)
print(A - B)
print(A * B)
print(abs(A))
print('-' * 16)


print(-A + B)
print(A)
print(-A)
print(+A)
print(A)
