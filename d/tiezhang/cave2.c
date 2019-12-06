//room: /d/tiezhang/cave2.c

inherit ROOM;

void init();
int do_lingwu(string);

void create()
{
        set("short","�ܶ�");
        set("long",@LONG
�����ƺ��Ǵ�˵�е����ư������ĵط��������ںڵĿ���̫�������Լ��
�ܿ���һ�㶴������һЩ��ֵĵ�ͼ(tu)�����룬���������ǲ��ǿ�����
��(kan)��ʲô�أ�
LONG );
        set("exits",([
                "out" : __DIR__"dong-2",
        ]));
        set("item_desc",([
                "tiesuo" : "ͼ�����ر�֪����ʲô���á�\n" ,
        ]));
        setup();
}

void init()
{
        add_action("do_lingwu","kan");
}

int do_lingwu(string arg)
{
        object ob;
        int c_skill;
        int exp;
        ob = this_player();
        exp=(int)ob->query("combat_exp");

        if (arg != "tu") return 0;
        c_skill=(int)ob->query_skill("strike", 1);

        if (ob->query("jing")<200)
                return notify_fail("��̫���ˣ��޷�����ʲô��\n");
//      if (c_skill< 250)
//              return notify_fail("����Ŷ�����ĥ�����ã��޷�����������ʲô��\n");
        if (exp*10 <= (c_skill*c_skill*c_skill)) {
                ob->receive_damage("jing", 80);
                return notify_fail("��ľ��鲻�����޷���������ʲô�ˡ�\n");
        }

        message_vision("$N��ϸ�Ŀ���ͼ����㱼��ƺ�������ʲô��\n",ob);
        ob->improve_skill("strike", random(100*ob->query_int()));
        ob->receive_damage("jing", 150);
        return 1;
}

