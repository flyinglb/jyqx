//      dadian.c ���
//      Designed by secret (����)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","���");
        set("long",@LONG
������ѩɽ�µĴ����빩���ŷ�������ɮ����������
���ġ�Զ����������������ϵ�Ĥ��(mobai)��������඼��
��
LONG );
        set("exits",([
                "east"  : __DIR__"cedian1",
                "west"  : __DIR__"cedian2",
                "south" : __DIR__"guangchang",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/lazhang" : 1,
		__DIR__"npc/xiang-ke" : 2,
        ]));
        set("valid_startroom", 1);
//      set("no_clean_up", 0);
        setup();
//      replace_program(ROOM);

        "/clone/board/xueshan_b"->foo();
}
void init()
{
        add_action("do_mobai","mobai");
}
int do_mobai(string arg)
{
        object ob;
        int c_skill;
        ob = this_player();

//      if (arg != "dao") return 0;
        c_skill=(int)ob->query_skill("lamaism", 1);

        if (ob->query("jing")<20)
        {
                message_vision("$N̫���ˣ�û�о���Ĥ�ݡ�\n",ob);
                return 1; 
        }
        if (c_skill> 300)
        {
                message_vision("$N�����޷�ͨ��Ĥ�������������Ϊ�ˡ�\n",ob);
                return 1; 
        }
        if (c_skill< 100)
        {
                message_vision("$N�����ڵľ�������ò������޷�ͨ��Ĥ�������������Ϊ��\n",ob);
                return 1; 
        }

        message_vision("$N��Է�����Ĥ�ݣ��������ķ���������\n",ob);
        ob->improve_skill("lamaism", random(10*ob->query("int")));
        ob->receive_damage("jing", 5);
        return 1;
}
