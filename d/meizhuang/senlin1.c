// senlin1.c
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "��ľ԰");
        set("long", @LONG
������÷ׯ�İ�ľ԰����һ�ߵ���������ߵ���һ�������޾�
��Сɭ��һ��������������������������������кܶ�в�������
�ֵ�������ľ��������һ�����(huang song)�ر�Ĵ�׳��������ï
�ܵ�֦Ҷ���棬�ƺ�����ʲô���ܡ��Ա�����һ������(pai zi)��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "south" : __DIR__"keting",
            "north" : __DIR__"neiyuan",
            "east" : __DIR__"senlin2",
            "west" : __DIR__"neitang",
        ]));
        set("item_desc", ([ /* sizeof() == 1 */
            "huang song" : "һ��ߴ�Ļ��ɣ���ס��������ߡ�\n",
            "pai zi" : "��ľʥ�֣�����Ī�룬ֻ��ֱ�У�������\n",
        ]));
        set("outdoors", "meizhuang");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
//        string dir;
        object me=this_player();

        if( !arg || arg=="" ) {write("������ʲô��\n");return 1;}

        if( arg=="huang song" ) {
                           write("���ֽŲ��ã����ֱ��ŵ���������......\n");
                if((int)me->query_skill("dodge",1)>=30)
                          {write("����ѽ�������������������Ķ��ˡ�\n");
                me->move(__DIR__"shuding1");

                 return 1;}
                write(RED"��ž����һ�����ֵ���ԭ����ˤ�˸��Ľų��졣\n"NOR);
                me->add("jing",-100);
                me->add("qi",-100);
                me->improve_skill("dodge", random(30));
                me->unconcious();

                return 1;
                }
}

