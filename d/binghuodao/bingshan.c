#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "��ɽ");
        set("long",@LONG
��������һ����ɽ֮�ϡ��㼫ĿԶ����ֻ������һ�ߣ���Χһ������ɽ,
����ֻ�к��˵��Ĵ���,��֪�Լ���Ʈ��δ�.
LONG);   
        set("no_clean_up", 0);
        setup();
     
}
int init ()
{
object ob=this_player();
ob->add("qi",-40);
ob->add("jing",-40);
}

