//ct.c
//call_out test command

inherit F_CLEAN_UP;

nosave int i = 0;

void do_call();

int main(object me, string arg)
{
        i = 0;
        write("Start test ... t: "+time()+"\n");
        call_out("do_call",0);
        return 1;
}

void do_call()
{
        log_file("ct","i: "+i+" t: "+time()+"\n");
//        if( i > 1000 ) return ;
        if( i > 10 ) return ;
        call_out("do_call",0);
        i++;
}
