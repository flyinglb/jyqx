// Room: /d/city2/jail.c
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "�̲�����");
        set("long", @LONG
�������̲����Σ�������ֻ��һ�ѷ�ù���굾�ݣ�����������
�룬ǽ��һ����ʺ�衣����Χ��ǽ��ȫ���õ�����䣬�Է�Ҫ��ײ
ǽ��ɱ�����۸߿���һ��������С�촰(window)��͸��һ����ɫ
��Ұ�����С����ڷ��䷸����˻���ߵĲҽ���һ�������Ķ�Ĥ��
һ�̲��ð�����
LONG );
        set("no_clean_up", 0);
        set("no_beg",1);
        set("no_fight",1);
        set("no_sleep_room",1);
        set("item_desc", ([
           "window": "̫��������Ϊʲô�о����������ů?\n",
        ]));
        set("objects", ([
                __DIR__"npc/yuzu" : 1,
        ]));
        setup();
        "/clone/board/jail_b"->foo();
//        replace_program(ROOM);
}

void init()
{
        object ob = this_player();

        ob->set("startroom", "/d/city2/jail");
        ob->set("xkx_jail", 1);
        message("vision",
           HIY "ֻ���η����ſ��һ�죬һ���������ļһﱻ���˽�����\n\n" NOR,
           environment(ob), ob);
        tell_object(ob, "����ٺٵ�Ц�ţ����������Ǵ�ʯͷ��ʺ�ӣ����𹫷�����...��\n");
}
