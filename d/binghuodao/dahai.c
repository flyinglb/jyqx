#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "���");
        set("long",@LONG
��������ãã��֮�С��㼫ĿԶ����ֻ������һ�ߣ���Χ�����ڵ㶼û�С�
����ֻ�к��˵��Ĵ�����
LONG);   
        set("no_clean_up", 0);
        setup();
       
}
int init ()
{
     object ob=this_player();
     ob->add("qi",-10);
     ob->add("jing",-10);
}

