#!/usr/bin/env python
import xmostest

def runtest_unit_tests():
    testlevel = 'smoke'
    resources = xmostest.request_resource('xsim')

    binary = 'app_unit_test/bin/app_unit_test.xe'
    tester = xmostest.ComparisonTester(open('app_unit_test/pass.expect'),
                                       'lib_neopixel',
                                       'neopixel_unit_tests',
                                       'neopixel_unit_tests')
    tester.set_min_testlevel(testlevel)
    xmostest.run_on_simulator(resources['xsim'], binary, tester=tester)

def runtest():
    runtest_unit_tests()

