// shandong3.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","ɽ��");
        set("long",@LONG
����һ��СС��ɽ����Ѫ������Ĳ���֮�ء���춴˵رȽ����أ�
��Һ���Ѱ��������������һ�Ź��������湩��ʲ�ᶫ�����㿴���塣
���ϻ���һЩģ�����������ͼ����Ҳ��֪����Щʲô��
LONG );
        set("exits",([
                "out" : __DIR__"shandong2",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/xuedao" :1,
                __DIR__"npc/x_lama" :1,
        ]));
        setup();
        "/clone/board/xuedao_b"->foo();
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
        int lvl = this_player()->query_skill("xue-dao",1);

        if ((int)ob->query_skill("longxiang", 1) < 20)
        {
                message_vision("$N�����󹦲���������������̵���ʲô��\n",ob);
                return 1;
        }
        if ((int)ob->query_skill("xue-dao", 1) > 50)
        {
                message_vision("$N��Ѫ��������ͳ�Խ���������ˡ�\n",ob);
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
        ob->improve_skill("xue-dao", random(ob->query("int")));
        ob->receive_damage("jing", 20);
        return 1;
}
