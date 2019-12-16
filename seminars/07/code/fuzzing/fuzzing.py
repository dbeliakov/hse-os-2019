import subprocess
from random import randint

MIN_LONG = -9223372036854775808
MAX_LONG = 9223372036854775807

MAX_NUMBER = 1e60
MIN_NUMBER = -1e60
MAX_COUNT = 20

TESTS_COUNT = 20

def correct():
    return randint(MIN_LONG, MAX_LONG)

def maybe_incorrect():
    return randint(MIN_NUMBER, MAX_NUMBER)

def create_test():
    l = randint(1, MAX_COUNT)
    inp = []
    for i in xrange(l):
        if randint(0, 1) == 0:
            inp.append(correct())
        else:
            inp.append(maybe_incorrect())
    out = []
    for i in inp:
        if MIN_LONG < i < MAX_LONG:
            out.append(1)
        else:
            out.append(-1)
    return inp, out

def main():
    cmd = ["./a.out"]
    for i in  xrange(TESTS_COUNT):
        inp, out = create_test()
        p = subprocess.Popen(
            subprocess.list2cmdline(cmd),
            shell=False,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )

        stdout, _ = p.communicate('\n'.join(map(str, inp)))
        stdout = [int(x.strip()) for x in stdout.split('\n') if len(x) > 0]

        for i, j in zip(out, stdout):
            if i != j:
                print "Wrong answer\n\nInput:\n" + '\n'.join(map(str, inp)) + \
                    "\n\nOutput:\n" + '\n'.join(map(str, stdout)) + '\n\nCorrect:\n' + '\n'.join(map(str, out))
                return

if __name__ == "__main__":
    main()
