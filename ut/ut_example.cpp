﻿/***************************************************************************/
#include "ut/ut.h"
#include "ut_testsut_my_app.h"



/***************************************************************************/



/***************************************************************************/
/* 테스트케이스1 */
/* 아래 함수 순서를 지켜야 함  */
ut_testfixture_setup(case1)
{
	ut_println("case1-setup");
}

ut_testfixture_teardown(case1)
{
	ut_println("case1-teardown");
}

ut_testcase_fixture
(
	case1,
	"case1-description",
	ut_testfixture_setup_instance(case1), 
	ut_testfixture_teardown_instance(case1)
)
{
	ut_println("case1");

	ut_testassert(1);
}

/***************************************************************************/
/* 테스트케이스2 */
ut_testcase(case2, "case2-description")
{
	ut_println("case2");
	ut_testassert(0);
	ut_testassert(1);
}


/***************************************************************************/
/* 테스트케이스3 */
ut_testcase(case3, ut_nullptr)
{
	ut_println("case3");
}

/***************************************************************************/
/* 테스트케이스4 */
ut_testcase(case4, ut_nullptr)
{
	ut_println("case4");
}



/***************************************************************************/
/* 테스트슈트1 */
/* 아래 함수 순서를 지켜야 함  */
ut_testfixture_setup(suite1)
{
	ut_println("suite1-setup");
}

ut_testfixture_teardown(suite1)
{
	ut_println("suite1-teardown");
}

ut_testsuite_case_begin(suite1)
ut_testsuite_case(case1)
ut_testsuite_case(case2)
ut_testsuite_case(case3)
ut_testsuite_case(case4)
ut_testsuite_case_end()

ut_testsuite_fixture
(
	suite1, 
	"suite1-description", 
	ut_testfixture_setup_instance(suite1), 
	ut_testfixture_teardown_instance(suite1)
)

/***************************************************************************/
/* 테스트슈트2 */
ut_testsuite_case_begin(suite2)
//ut_testsuite_case(case1)
ut_testsuite_case(case2)
ut_testsuite_case(case3)
ut_testsuite_case(my_app_case1)
ut_testsuite_case_end()

ut_testsuite(suite2, ut_nullptr)




/***************************************************************************/
int main()
{	
	ut_testinvoke_initialize();

	int a = 3;

	ut_testrunner(ut_testsuite_instance(suite1), &a);
	ut_testrunner(ut_testsuite_instance(suite2), ut_nullptr);

	ut_testrunner(ut_testsuite_instance(my_app_suite1), ut_nullptr);

	return 0;
}
