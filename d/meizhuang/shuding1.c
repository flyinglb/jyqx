// shuding1.c
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "������");
        set("long", @LONG
�����������������Ķ��ˣ�����������Կ���һƬ����
�������֣�����������ͬ����һ��ݵ���һ����Զ��
���Կ�������ԼԼ��һ��Ρ��ĸ�ɽ��
LONG
        );
        set("book_count",1);
        set("exits", ([ /* sizeof() == 1 */
            "down" : __DIR__"senlin1",
        ]));
        set("item_desc", ([ /* sizeof() == 1 */
            "song zhen" : "���ط������뿴�����������ط��Ĳ�̫һ����",
        ]));
        set("outdoors", "meizhuang");
        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_pull", "pull");
}
int do_pull(string arg)
{
        object me , ob;
        me = this_player();
        if (arg == "song zhen" && !present("qinpu", me) && query("book_count") >= 1)
        {
                add("book_count", -1);
                ob=new("/clone/book/qinpu");
                ob->move(__DIR__"shuding1");
                message_vision("$N������ƿ��������룬�ۣ������Ȼ��һ���顣\n", me);
                return 1;
        }
        else {
                me->receive_damage("qi", 20);
                message_vision("$N�����Ѿ�������������Ѫ���ܣ���Ҫ�����ˡ�\n", me);
                return 1;
             }
}

