// shandong.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����ʯ����б����һ�����ùǣ������·��������߰˳ɣ�������
����Ȼ�пɼ����Ǹ����Ρ���ʯ���б��������ɲ��������ǰ���
�����˵ķ���ʮ���ѽ���׶��ʯ�����м��ٷ��������̳ɵļ�ª����
(map) ��ͼ�ξ�����ʯ���ϳ�����ʮ������(word)��Ҳ�����������̡�
ʮ����֮�ԣ��и�����͹����ʯ��֮�ϣ�����һ�ѽ�������ʯ�ڣ�ֱ
��������
LONG );
        set("outdoors", "jinshe");
        set("sword_count", 1);
        set("exits", ([ /* sizeof() == 2 */
            "south" : __DIR__"yongdao2",
        ]));
        set("objects", ([
            __DIR__"obj/jinshe-zhui" : 1,
            __DIR__"obj/skeleton" : 1,
        ]));
        set("item_desc", ([
            "map"  : "ʯ��ÿ�����ξ�����ͬ���������㣬�������䡣\n",
            "word" : "���ر�������������Ե����������������ĪԹ����\n",
        ]) );
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_think", "think");
        add_action("do_pull", "pull");
}
int do_pull(string arg)
{
        object ob, me= this_player();
        if (arg != "sword") return 0;
        if (query("sword_count") < 1)
                return notify_fail("�������Ѿ����˰����ˡ�\n");
        if (this_player()->query("neili") < 1000)
        {
                message_vision(
"$N����������ס��������һ�Σ�ȴ����˿��������������ʯ��һ�㡣\n", me);
                me->set("neili", 10);
                return 0;
        }
        ob = new(__DIR__"obj/jinshe-jian");
        ob->move(me);
                message_vision(
"$N������ס������Ǳ���������͵�һ���죬���˳����������¹�Ȼ���н���\n", me);
        me->add("neili",-1000);
        add("sword_count", -1);
        return 1;
}
int do_think(string arg)
{
        object ob;
        int c_exp,c_skill;
        ob = this_player();

        if (arg != "map") return 0;
        c_skill=(int)ob->query_skill("jinshe-jian", 1);
        c_exp=ob->query("combat_exp");

        if ((c_skill*c_skill*c_skill/10)> c_exp)
        {
                message_vision("$N��ʵս���鲻�㣬�޷�����ʯ�����ݡ�\n",ob);
                return 1; 
        }
        if (ob->query("jing")<20)
        {
                message_vision("$N̫���ˣ������޷�����ʯ�����ݡ�\n",ob);
                return 1; 
        }
        if (c_skill> 50)
        {
                message_vision("$N����ʯ������̫��ǳ�ˡ�\n",ob);
                return 1; 
        }

        message_vision("$N�����ʯ�ھ�˼���ã��Խ��߽�����������\n",ob);
        ob->improve_skill("jinshe-jian", random(10*ob->query("int")));
        ob->receive_damage("jing", 5);
        return 1;
}


