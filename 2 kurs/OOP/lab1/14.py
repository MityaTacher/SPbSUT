from __future__ import annotations
import math


class Rational:
    def __init__(self, numerator: int = 0, denominator: int = 1, frac: str = ''):
        if frac:
            frac = frac.split('/')
            if len(frac) != 2:
                raise TypeError("Not rational fraction.")
            frac = [int(i) for i in frac]
            numerator = frac[0]
            denominator = frac[1]
        if denominator == 0:
            raise ZeroDivisionError("Denominator can't be 0.")
        self.numerator = numerator
        self.denominator = denominator
        self.fix_signs()

    def reduce(self) -> Rational:
        gcd = math.gcd(self.numerator, self.denominator)
        self.numerator //= gcd
        self.denominator //= gcd
        self.fix_signs()
        return self

    def fix_signs(self) -> Rational:
        if (mul := self.numerator * self.denominator) < 0:
            self.numerator = -abs(self.numerator)
            self.denominator = abs(self.denominator)
            # print(f'\t<0;{self.numerator, self.denominator}')
        elif mul > 0:
            # print(f'\t>0;{self.numerator, self.denominator}')

            if self.numerator < 0:
                self.numerator = abs(self.numerator)
                self.denominator = abs(self.denominator)
        # else:
            # print(f'\t=0;{self.numerator, self.denominator}')
        return self

    def __str__(self) -> str:
        if self.denominator == 1:
            return f'{self.numerator}'
        return f'{self.numerator}/{self.denominator}'

    def __neg__(self) -> Rational:
        return Rational(-self.numerator, self.denominator)

    def __pos__(self) -> Rational:
        return self

    def __abs__(self) -> Rational:
        return Rational(abs(self.numerator), abs(self.denominator))

    def __add__(self, other: Rational | int) -> Rational:  # a/b + c/d = (ad + bc)/bd
        if isinstance(other, int):
            other = Rational(other)
        if isinstance(other, Rational):
            numerator = self.numerator * other.denominator + self.denominator * other.numerator
            denominator = self.denominator * other.denominator
            fracton = Rational(numerator, denominator)
            return fracton.reduce()
        return NotImplemented

    def __radd__(self, other: int) -> Rational:
        return self.__add__(other)

    def __sub__(self, other: Rational | int) -> Rational:  # a/b - c/d = (ad - bc)/bd
        if isinstance(other, int):
            other = Rational(other)
        if isinstance(other, Rational):
            numerator = self.numerator * other.denominator - self.denominator * other.numerator
            denominator = self.denominator * other.denominator
            fracton = Rational(numerator, denominator)
            return fracton.reduce()
        return NotImplemented

    def __rsub__(self, other: int) -> Rational:
        return Rational(other).__sub__(self)

    def __mul__(self, other: Rational | int) -> Rational:  # a/b * c/d = ac / bd
        if isinstance(other, int):
            other = Rational(other)
        if isinstance(other, Rational):
            numerator = self.numerator * other.numerator
            denominator = self.denominator * other.denominator
            fracton = Rational(numerator, denominator)
            return fracton.reduce()
        return NotImplemented

    def __rmul__(self, other: int) -> Rational:
        return self.__mul__(other)

    def __truediv__(self, other: Rational | int) -> Rational:  # a/b / c/d = ad/bc
        if isinstance(other, int):
            other = Rational(other)
        if isinstance(other, Rational):
            numerator = self.numerator * other.denominator
            denominator = self.denominator * other.numerator
            fracton = Rational(numerator, denominator)
            return fracton.reduce()
        return NotImplemented

    def __rtruediv__(self, other: int) -> Rational:
        return Rational(other).__truediv__(self)

    def __eq__(self, other: Rational | int) -> bool:  # ==
        if isinstance(other, int):
            other = Rational(other)
        if isinstance(other, Rational):
            return self.numerator * other.denominator == self.denominator * other.numerator
        return NotImplemented

    def __ne__(self, other: Rational | int) -> bool:  # !=
        if isinstance(other, int):
            other = Rational(other)
        if isinstance(other, Rational):
            return self.numerator * other.denominator != self.denominator * other.numerator
        return NotImplemented

    def __lt__(self, other: Rational | int) -> bool:  # <
        if isinstance(other, int):
            other = Rational(other)
        if isinstance(other, Rational):
            return self.numerator * other.denominator < self.denominator * other.numerator
        return NotImplemented

    def __le__(self, other: Rational | int) -> bool:  # <=
        if isinstance(other, int):
            other = Rational(other)
        if isinstance(other, Rational):
            return self.numerator * other.denominator <= self.denominator * other.numerator
        return NotImplemented

    def __gt__(self, other: Rational | int) -> bool:  # >
        if isinstance(other, int):
            other = Rational(other)
        if isinstance(other, Rational):
            return self.numerator * other.denominator > self.denominator * other.numerator
        return NotImplemented

    def __ge__(self, other: Rational | int) -> bool:  # >=
        if isinstance(other, int):
            other = Rational(other)
        if isinstance(other, Rational):
            return self.numerator * other.denominator >= self.denominator * other.numerator
        return NotImplemented


A = Rational()
B = Rational(3, 7)
C = Rational(frac="-14/-8")
print(A)
print(B)
# print(C)
print(C.reduce())
# print(B + C)
# print(1 + B)
# print(B + 1)
#
# print(C - B)
# print(1 - B)
# print(C - 1)
#
# print(B * C)
# print(B * 2)
# print(2 * B)
#
# print(B / C)
# print(2 / B)
# print(B / 2)
#
# print(C == Rational(7, 4))
# print(Rational(2) == 2)
# print(2 == Rational(2))
#
# print(C != B)
# print(Rational(2) != 2)
# print(2 != Rational(2, 4))
#
# print(B < C)
# print(B < 1)
# print(1 > C)
# print(2 <= Rational(2))
# print(B >= C)
