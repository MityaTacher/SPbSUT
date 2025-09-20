from __future__ import annotations
from abc import ABC, abstractmethod


class Base(ABC):
    def __init__(self, **kwargs):
        super().__init__(**kwargs)

    def __del__(self):
        print(f'Object of class {self.__class__.__name__} destructed')

    @abstractmethod
    def __str__(self):
        pass

    @abstractmethod
    def copy(self):
        pass


class COne(Base, ABC):
    def __init__(self, l: int | None = None, s: str | None = None, cls_one_copy: COne | None = None, **kwargs):
        super().__init__(**kwargs)
        self._l = l
        self._s = s
        if cls_one_copy:
            self._l = cls_one_copy._l
            self._s = cls_one_copy._s

    def __str__(self) -> str:
        return f'{self._l}, {self._s}'

    def copy(self, other: COne):
        self._l = other._l
        self._s = other._s

    @property
    def value_l(self) -> int:
        return self._l

    @value_l.setter
    def value_l(self, value):
        self._l = value

    @property
    def value_s(self) -> str:
        return self._s

    @value_s.setter
    def value_s(self, value):
        self._s = value


class CTwo(Base, ABC):
    def __init__(self, ll: int | None = None, obj: COne | None = None, cls_two_copy: CTwo | None = None, **kwargs):
        super().__init__(**kwargs)
        self._ll = ll
        self._obj = obj
        if cls_two_copy:
            self._ll = cls_two_copy._ll
            self._obj = cls_two_copy._obj

    def __str__(self) -> str:
        return f'{self._ll}, {self._obj}'

    def copy(self, other: CTwo):
        self._ll = other._ll
        self._obj = other._obj

    @property
    def value_l(self):
        return self._ll

    @value_l.setter
    def value_l(self, value: int):
        self._ll = value

    @property
    def value_obj(self):
        return self._obj

    @value_obj.setter
    def value_obj(self, value: COne):
        self._obj = value


class CTree(CTwo, ABC):
    def __init__(self, field: int | None = None, cls_two_obj: CTwo | None = None,
                 cls_three_copy: CTree | None = None, **kwargs):
        super().__init__(**kwargs)
        self._field = field
        if cls_two_obj:
            self.value_l = cls_two_obj.value_l
            self.value_obj = cls_two_obj.value_obj
        if cls_three_copy:
            self._field = cls_three_copy._field
            self.value_l = cls_three_copy.value_l
            self.value_obj = cls_three_copy.value_obj

    def __str__(self) -> str:
        # return f'{self._field, self.value_l, self.value_obj.value_l, self.value_obj.value_s}'
        return ', '.join(str(i) for i in [self._field, self.value_l, self.value_obj.__str__()])

    def copy(self, other: CTree):
        self._field = other._field
        self.value_obj = other.value_obj
        self.value_l = other.value_l

    @property
    def value_field(self):
        return self._field

    @value_field.setter
    def value_field(self, value: int):
        self._field = value


class CFour(CTree, ABC):
    def __init__(self, field2: int | None = None, cls_tree_obj: CTree | None = None,
                 cls_four_copy: CFour | None = None, **kwargs):
        super().__init__(**kwargs)
        self._field2 = field2
        if cls_tree_obj:
            self.value_l = cls_tree_obj.value_l
            self.value_obj = cls_tree_obj.value_obj
        if cls_four_copy:
            self._field2 = cls_four_copy._field2
            self.value_l = cls_four_copy.value_l
            self.value_obj = cls_four_copy.value_obj

    def __str__(self) -> str:
        return ', '.join(str(i) for i in [self._field2, self.value_field, self.value_l, self.value_obj.__str__()])

    def copy(self, other: CFour):
        self._field2 = other._field2
        self.value_field = other.value_field
        self.value_obj = other.value_obj
        self.value_l = other.value_l

    @property
    def value_field2(self):
        return self._field2

    @value_field2.setter
    def value_field2(self, value: int):
        self._field2 = value


def print_all(clss: list | tuple, count: int | None = None):
    for cls in clss:
        print(cls)


a = COne(1, '123')
b = COne(cls_one_copy=a)
a.value_s = '42'
c = CTwo(ll=17, obj=b)
d = CTree(field=17, cls_two_obj=CTwo(18, COne(19, 'hi')))
d.value_l = 18
f = CTree(field=10, ll=17, obj=b)

z = CFour(field2=12, field=10, ll=13, obj=COne(l=7, s='hello'))

print(z)
print(z.value_field2)
print(z.value_field)
print(z.value_l)

print('-----')

print_all([a, b, c, d, f, z])

#
# class COne_:
#     def __init__(self, l: int | None = None, s: str | None = None, cls: COne | None = None):
#         self._l = l
#         self._s = s
#         if cls:
#             self._l = cls._l
#             self._s = cls._s
#
#     def __del__(self):
#         print('Object of class COne destructed')
#
#     def __str__(self) -> str:
#         return f'{self._l}, {self._s}'
#
#     def copy(self, other: COne):
#         self._l = other._l
#         self._s = other._s
#
#     @property
#     def value_l(self) -> int:
#         return self._l
#
#     @value_l.setter
#     def value_l(self, value):
#         self._l = value
#
#     @property
#     def value_s(self) -> str:
#         return self._s
#
#     @value_s.setter
#     def value_s(self, value):
#         self._s = value
#
#
# class CTwo_:
#     def __init__(self, l: int | None = None, obj: COne | None = None, cls: CTwo | None = None):
#         self._l = l
#         self._obj = obj
#         if cls:
#             self._l = cls._l
#             self._obj = cls._obj
#
#     def __del__(self):
#         print(f'Object of class CTwo destructed')
#
#     def __str__(self) -> str:
#         return f'{self._l}, {self._obj}'
#
#     def copy(self, other: CTwo):
#         self._l = other._l
#         self._obj = other._obj
#
#     @property
#     def value_l(self):
#         return self._l
#
#     @value_l.setter
#     def value_l(self, value: int):
#         self._l = value
#
#     @property
#     def value_obj(self):
#         return self._obj
#
#     @value_obj.setter
#     def value_obj(self, value: COne):
#         self._obj = value
#
#
# class CTree_(CTwo):
#     def __init__(self, field: int | None = None, cls_ctwo: CTwo | None = None,
#                  cls_two_copy: CTree | None = None):
#         super().__init__()
#         self._field = field
#         if cls_ctwo:
#             self.value_l = cls_ctwo.value_l
#             self.value_obj = cls_ctwo.value_obj
#         if cls_two_copy:
#             self._field = cls_two_copy._field
#             self.value_l = cls_two_copy.value_l
#             self.value_obj = cls_two_copy.value_obj
#
#     def __del__(self):
#         print(f'Object of class CThree destructed')
#
#     def __str__(self) -> str:
#         return f'{self._field, self.value_l, self.value_obj.value_l, self.value_obj.value_s}'
#
#     def copy(self, other: CTree):
#         self._field = other._field
#
#     @property
#     def value_field(self):
#         return self._field
#
#     @value_field.setter
#     def value_field(self, value: int):
#         self._field = value
