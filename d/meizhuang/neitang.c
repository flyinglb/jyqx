// neitang.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ƫ��"); 
        set("long", @LONG
����һ��û���κζ����ķ��ӣ��ıڿյ����ģ�������һ�����
�õģ���û�����ü�����װ�εķ��䣬���е�ǽ�ϻ���һ���ڻ�����
������Ŀ�����ž���ʮ����ħ�ѪΪ�ˣ�ʮ���ħѪ������һֻ�ʺ�
�����ģ����ĵ��۾���Ȼ���÷ǳ���������ȸʯ���ɵġ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"senlin1",
        ]));

        set("no_clean_up", 0);
        set("item_desc", ([
            "eye": "һ��а�����ȸʯ������ҫ�۵ĺ�⡣\n"
        ]) ); 
        setup();
}
void init()
{
        add_action("do_push", "push");
}
int do_push(string arg)
{
//        string dir;
        object me=this_player();

        if( !arg || arg=="" ) {write("������ʲô��\n");return 1;}

        if( arg=="eye" ) {
                write("��ʹ������һ�����ĵ��۾���ǽ����Ȼ������\n");
                if((int)me->query_skill("force",1)>=100)
                {write("˳��ǽ�������ļз죬�������������ҡ�\n");
                me->move(__DIR__"mishi");

                 return 1;}
                write("����������һ�����ĵ��۾�����ʲô��û�з�����\n");

                me->add("jing",-10);
                me->add("qi",-10);


                return 1;

                 }
}

