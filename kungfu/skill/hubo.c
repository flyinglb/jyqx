// hubo.c
inherit ITEM;
//inherit SKILL;
void create() { seteuid(getuid()); }
void init()
{
    add_action("do_hubo","hubo");
}
string type() { return "knowledge"; }
int valid_learn(object me) 
{
        if( (int)me->query("int") > 25 ) 
           return  notify_fail("������Բ��ʺ�ѧϰ˫�ֻ���֮��!\n" ) ;
    return 1;
}
void do_hubo ( string arg )
{
    write( "��ȫ����ɣ���������ʼ�˹����ˡ�\n" );
    return ;
}
