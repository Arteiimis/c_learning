#include "htime.h"

int main()
{
    class time t1;
    class time *t1_ptr = &t1;
    class time &t1_ref = t1;

    t1.input_time();
    cout << t1.output_time() << endl;
    cout << t1.output_hour() << "时" << t1.output_minute() << "分" << t1.output_second() << "秒" << endl;

    t1_ptr->input_time();
    cout << t1_ptr->output_time() << endl;
    cout << t1_ptr->output_hour() << "时" << t1_ptr->output_minute() << "分" << t1_ptr->output_second() << "秒" << endl;
    
    t1_ref.input_time();
    cout << t1_ref.output_time() << endl;
    cout << t1_ref.output_hour() << "时" << t1_ref.output_minute() << "分" << t1_ref.output_second() << "秒" << endl;

    return 0;
}