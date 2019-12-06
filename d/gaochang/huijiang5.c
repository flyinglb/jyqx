// Room: /d/xingxiu/luzhou.c
// Jay 3.25/96
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��ɳĮ�ľ�ͷ������һ�����ޡ�������Ͻ��ѵ�һ���Ĳ�ԭ����ԭ�ϵ�ҹ
����ܸߡ����������Ǻ�������ݺ�С��ɢ�������㡣����ԼԼ�����Ʈ��
������ĸ����������ס�Ź�������, �Է�����ȺΪ������ľ������һ�ۿ���
������̨����һ��ľ��ר���ڿʵ����˺�ˮ��������һ��ϵء�
LONG
        );
        set("resource/water", 1);
        set("exits", ([
                "westup" : __DIR__"huijiang2",
                "southwest" : __DIR__"huijiang3",
                "northeast" : __DIR__"huijiang6",
                "north" : __DIR__"huijiang7",
        ]));
        set("objects", ([
            __DIR__"npc/yang" : 3,
            __DIR__"npc/su" : 1,
            __DIR__"npc/obj/hamigua" : 2,
        ]));
        setup();
//        replace_program(ROOM);
}
void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"ſ�ڿ������ľ�̨����ľ��Ҩ��һ��ˮ�ȡ�\n"
            , environment(me), ({me}) );
            write("�����һ�ھ��д���ɽ������������ѩˮ����ֱ���ۻ���\n");
        }
        else write("���Ų�ҪǮ��ˮ����ô�ȣ�������?\n");
        return 1;
}
