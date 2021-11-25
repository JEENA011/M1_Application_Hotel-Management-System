#include "../unity/unity.h"
#include "../inc/application.h"

/* Prototypes for all the test functions */
void enter_name(void);
void find_name(void);
void find_room(void);
void checkout_guest(void);
void view_bookings(void);

void setUp(){}
void tearDown(){}

int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
   RUN_TEST( enter_name );
   RUN_TEST (find_name);
   RUN_TEST (find_room);
   RUN_TEST (checkout_guest);
   RUN_TEST (view_bookings);
   
    /* Close the Unity Test Framework */
   return UNITY_END();

}

void enter_name(void)
{
   int A=3,B=2,answer=5; 
   TEST_ASSERT_EQUAL(answer ,enter_name(A,B) );
}

void find_name(void)
{
    int C=9,D=0,Answer=9;
   TEST_ASSERT_EQUAL( Answer, find_name(C,D) );
}

void checkout_guest(void)
{
    int E=6,F=7,ans=13;
   TEST_ASSERT_EQUAL( ans,checkout_guest(E,F) );
}


void find_room(void)
{
    int G=5,H=5,answ=10;
   TEST_ASSERT_EQUAL( answ,find_room(G,H) );
}


void view_bookings(void)
{
   int I=4,J=3,answe=7;
   TEST_ASSERT_EQUAL( answe,view_bookings(I,J) );
}