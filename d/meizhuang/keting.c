// keting.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ӭ��ͤ"); 
        set("long", @LONG
ͨ��������磬��������÷ׯ��ӭ��ͤ��������Ȼֻ��һ��ʯ��
����ʯ�ʣ���ȴ��һ����Ⱦ��ʯ�ʺ�ʯ��֮��Ŀ�϶�ܴ����Ƿ���
�����������໥���ѡ�һλ������վ��ͤǰ�����㹰��΢Ц��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"dating",
            "north" : __DIR__"senlin1",
        ]));

        set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/shi.c" : 1,
        ]));
        set("no_clean_up", 0);
        set("item_desc", ([
            "table": "һ�ź�ƽ����ʯ��������......�Լ��°ɡ�\n"
        ]) );

        setup();
}
void init()
{
        add_action("do_zuan", "zuan");
}
int do_zuan(string arg)
{
//        string dir;
        object me=this_player();

        if( !arg || arg=="" )
        {
                write("��Ҫ���Ķ��ꣿ\n");return 1;
        }
        if( arg=="table" )
        {
                write("��������ŵ��Ƶ�ʯ���ĺ��棬����������һ��С����\n");
                if((int)me->query_skill("dodge",1)>=30)
                {
                      write("��Ѿ���ţ����֮���������Լ�����һ�������صĵص��\n");
                      me->move(__DIR__"didao1");
                      return 1;
                }
                write(RED"����������һ�º����һ��С���������겻��ȥ��\n"NOR);
                me->add("jing",-10);
                me->add("qi",-10);

                return 1;
        }
}

