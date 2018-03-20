#!/usr/bin/env python
import xmostest

if __name__ == "__main__":
    xmostest.init()

    xmostest.register_group("lib_neopixel",
                            "neopixel_unit_tests",
                            "Unit test",
    """ Unit tests for the neopixel array
""")

    xmostest.runtests()

    xmostest.finish()
