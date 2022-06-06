import turtle
import math
import random

class tanks:
    def __init__(
        self, x, y, angle, size, v, health, color, name, active, targetx, targety
    ):
        self.x = x
        self.y = y
        self.size = size
        self.angle = angle
        self.v = v
        self.health = health
        self.color = color
        self.name = name
        self.active = active
        self.targetx = targetx
        self.targety = targety
        self.tut = turtle.Turtle()
        self.tut.hideturtle()
        self.tut.speed(0)
    def draw(self):
        self.tut.clear()
        self.tut.color(self.color)
        self.tut.pu()
        self.tut.goto(self.x, self.y - self.size)
        self.tut.pd()
        self.tut.setheading(0)
        self.tut.circle(self.size)
        self.tut.pu()
        self.tut.goto(self.x, self.y)
        self.tut.pd()
        self.tut.goto(
            self.x + math.cos(math.radians(self.angle)) * self.size * 1.5,
            self.y + math.sin(math.radians(self.angle)) * self.size * 1.5,
        )
    def move(self):
        self.x += math.cos(math.radians(self.angle)) * self.v
        self.y += math.sin(math.radians(self.angle)) * self.v
        self.draw()
    def target(self, x, y):
        self.targetx = x
        self.targety = y
        self.angle = self.tut.towards(self.targetx, self.targety)

def kmove():
    global velocity
    velocity = 0.15

def kstop():
    global velocity
    velocity = 0

def kleft():
    global rotate
    rotate = 1

def kleftstop():
    global rotate
    rotate = 0

def kright():
    global rotate
    rotate = -1

def krightstop():
    global rotate
    rotate = 0

def kend():
    global end
    end = 1

def control(t):
    t.angle += rotate
    t.v = velocity

screen = turtle.Screen()
screen.setup(500, 500)
screen.setworldcoordinates(0, 0, 200.0, 200.0)
screen.tracer(0)
screen.onkeypress(kmove, "Up")
screen.onkeyrelease(kstop, "Up")
screen.onkeypress(kleft, "Left")
screen.onkeyrelease(kleftstop, "Left")
screen.onkeypress(kright, "Right")
screen.onkeyrelease(krightstop, "Right")
screen.onkeypress(kend, "Escape")
turtle.hideturtle()
velocity = 0
rotate = 0
end = 0
user = tanks(10, 10, 0, 5, 0, 10, "blue", "Tank 1", True, 0, 0)
# __init__(self, x, y, angle, size, v, health, color, name, active, targetx, targety)
numtanks = 4
enemy = [x for x in range(numtanks)]
for i in range(numtanks):
    x = random.randint(5, 195)
    y = random.randint(5, 195)
    angle = random.randint(0, 360)
    enemy[i] = tanks(x, y, angle, 5, 0.1, 10, "red", "Tank 1", True, user.x, user.y)
screen.listen()
while not end:
    control(user)
    user.move()
    for i in enemy:
        i.target(user.x, user.y)
        i.move()
    screen.update()