from math import ceil


class line:

    def __init__(self, start, end):
        self.start = start
        self.end = end

    def dda_draw(self):

        x1, y1 = self.start
        x2, y2 = self.end

        dx = x2 - x1
        dy = y2 - y1

        m = dy / dx if dx != 0 else float("inf")
        m = abs(m)

        print("DDA Line Drawing Algorithm")
        print(f"({x1},{y1})")

        while x1 < x2 or y1 < y2:

            if m <= 1:
                x1 += 1
                y1 += m
            else:
                y1 += 1
                x1 += 1 / m
            print(f"({ceil(x1)},{ceil(y1)})")

    def bersenham_draw(self):

        x1, y1 = self.start
        x2, y2 = self.end

        dx = x2 - x1
        dy = y2 - y1

        m = dy / dx if dx != 0 else float("inf")
        m = abs(m)

        print("Bresenham Line Drawing Algorithm")
        print(f"({x1},{y1})")

        if m <= 1:

            alpha = 2 * (dy - dx)
            beta = 2 * dy
            p = beta - dx

            while x1 < x2:

                if p >= 0:
                    p += alpha
                    x1 += 1
                    y1 += 1
                else:
                    p += beta
                    x1 += 1
                print(f"({ceil(x1)},{ceil(y1)})")
        else:

            alpha = 2 * (dx - dy)
            beta = 2 * dx
            p = beta - dy

            while y1 < y2:

                if p >= 0:
                    p += alpha
                    x1 += 1
                    y1 += 1
                else:
                    p += beta
                    y1 += 1
                print(f"({ceil(x1)},{ceil(y1)})")


class Circle:
    def __init__(self, center, radius):
        self.center = center
        self.radius = radius

    def midpoint_draw(self):
        cx, cy = self.center
        x = 0
        y = self.radius
        r = self.radius
        p = 1 - r

        print("Midpoint Circle Drawing Algorithm")
        print(f"({x},{y})")

        all_points = []

        while x < y:

            if p >= 0:
                x += 1
                y -= 1
                p += 2 * x - 2 * y + 1
                print(f"({x},{y})")

            else:
                x += 1
                p += 2 * x + 1
                print(f"({x},{y})")

            points = [
                (cx + x, cy + y),
                (cx - x, cy + y),
                (cx + x, cy - y),
                (cx - x, cy - y),
                (cx + y, cy + x),
                (cx - y, cy + x),
                (cx + y, cy - x),
                (cx - y, cy - x),
            ]
            all_points.extend(points)
            print("")

        print("Points on the Circle:")
        counter = 0
        for point in all_points:
            print(f"({point[0]},{point[1]})", end="  ,  ")
            counter += 1
            if counter % 8 == 0:
                print()


class ellipse:
    def __init__(self, center, a, b):
        self.center = center
        self.a = a
        self.b = b

    def midpoint_draw(self):
        xc, yc = self.center
        a = self.a
        b = self.b

        x = 0
        y = b

        all_points = []
        print("Midpoint ellipse Drawing Algorithm")
        print("area I:")
        print(f"({x},{y})")

        # I area:
        p = (b**2) - ((a**2) * b) + ((a**2) / 4)

        while ((b**2) * x) < ((a**2) * y):

            if p < 0:
                x += 1
                p += 2*b*b*x + b*b
                print(f"({x},{y})")
            else:
                x += 1
                y -= 1
                p += 2*b*b*x - 2*a*a*y + b*b
                print(f"({x},{y})")

            points = [
                (xc + x, yc + y),
                (xc - x, yc + y),
                (xc + x, yc - y),
                (xc - x, yc - y),
            ]
            all_points.extend(points)

        # II area:
        print("area II:")
        p = (
            ((b**2) * ((x + (0.5)) ** 2))
            + ((a**2) * ((y - 1) ** 2))
            - ((a**2) * (b**2))
        )

        while y > 0:

            if p > 0:
                y -= 1
                p -= 2*a*a*y + a*a
                print(f"({x},{y})")
            else:
                x += 1
                y -= 1
                p += 2*b*b*x - 2*a*a*y + a*a
                print(f"({x},{y})")

            points = [
                (xc + x, yc + y),
                (xc - x, yc + y),
                (xc + x, yc - y),
                (xc - x, yc - y),
            ]
            all_points.extend(points)

        print("Points on the ellipse:")
        counter = 0
        for point in all_points:
            print(f"({point[0]},{point[1]})", end="  ,  ")
            counter += 1
            if counter % 4 == 0:
                print()

#line.dda_draw(line(( , ), ( , )))
#line.bersenham_draw(line(( , ), ( , )))
#Circle.midpoint_draw(Circle(( 10,20 ),50 ))
ellipse.midpoint_draw(ellipse((3 ,1  ),10 ,5 ))
