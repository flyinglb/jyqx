//      zoulang3.c ����
//      97/04/09

inherit ROOM;

void create()
{
        set("short","����");
        set("long",@LONG
������ѩɽ���ڵ����ȡ������е��İ����컨������
һЩ��֪��ȷ�к���ĵ�̣�ǽ�������Ǻ�ͨ�׵ķ𾭹�
�±ڻ��ˡ����ϵ��ż���󺣵�������
LONG );
        set("exits",([
                "north"    : __DIR__"neidian",
                "eastdown" : __DIR__"zoulang1",
                "westdown" : __DIR__"zoulang2",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

void init()
{
        add_action("do_watch", "watch");
        add_action("do_watch", "kan");
        add_action("do_watch", "mianbi");
        add_action("do_watch", "face");
}

int do_watch()
{
        object ob = this_player();
        int lvl = this_player()->query_skill("shenkong-xing",1);

        if ((int)ob->query_skill("xiaowuxiang", 1) < 10)
        {
                message_vision("$N��С���๦����������������̵���ʲô��\n",ob);
                return 1;
        }
        if ((int)ob->query_skill("shenkong-xing", 1) > 40)
        {
                message_vision("$N���������ͳ�Խ���������ˡ�\n",ob);
                return 1;
        }
        if((lvl * lvl * lvl) > (int)ob->query("combat_exp"))
        {
                message_vision("$N��ʵս���鲻�㣬�޷�����������ݡ�\n",ob);
                return 1;
        }
        if (ob->query("jing")<20)
        {
                 message_vision("$N̫���ˣ������޷�����������ݡ�\n",ob);
                 return 1;
        }
        message_vision("$N����ű���ͼ����Ħ���ã���������\n",ob);
        ob->improve_skill("shenkong-xing", random(ob->query("int")));
        ob->receive_damage("jing", 20);
        return 1;
}

