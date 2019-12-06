// sanqingdian.c �����
// by Xiang

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
���������������������䵱�ɻ�͵ĵص㡣����Ԫʼ����̫�ϵ�
���͵�������������㰸���������ơ���ǽ���ż���̫ʦ�Σ����Ϸ��ż�
�����ţ��м�����ʿ�Ͳΰ������ڤ����վ����޵�(xiu dao)����������
�����ȣ�����������Ĺ㳡���ϱ��Ǻ�Ժ��
LONG );
        set("valid_startroom", 1);
        set("exits", ([
                "north" : __DIR__"guangchang",
                "south" : __DIR__"houyuan",
                "east"  : __DIR__"donglang1",
                "west"  : __DIR__"xilang",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/guxu" : 1,
                CLASS_D("wudang") + "/song" : 1
        ]));
//        set("no_clean_up", 0);
        setup();
        "/clone/board/wudang_b"->foo();
}

void init()
{
        add_action("do_xiu", "xiu");
}
int do_xiu(string arg)
{
        object ob;
        int c_skill;
        ob = this_player();

        if (arg != "dao") return 0;
        c_skill=(int)ob->query_skill("taoism", 1);

        if (ob->query("jing")<20)
        {
                message_vision("$N̫���ˣ�û�о���ڤ����ա�\n",ob);
                return 1; 
        }
        if (c_skill> 300)
        {
                message_vision("$N�����޷�ͨ��ڤ���޵�����ߵ�����Ϊ�ˡ�\n",ob);
                return 1; 
        }
        if (c_skill< 100)
        {
                message_vision("$N�ƺ������ӵľ�������ò������޷�ڤ���޵�����ߵ�����Ϊ��\n",ob);
                return 1; 
        }

        message_vision("$Nڤ����ա������޵����Ե�ѧ�ķ���������\n",ob);
        ob->improve_skill("taoism", random(10*ob->query("int")));
        ob->receive_damage("jing", 5);
        return 1;
}
