// xiaolu8.c ��ɽС·
// By Lgg,1998.10

inherit ROOM;
string l_pattern();

void create()
{
        set("short", "��ɽС·");
        set("long", @LONG
�����Ǻ�ɽ�ϵ�С·������С·�������˹������޳����ģ�
Ҳ��ֻ����ǰ�Ĳ�ҩ�˲ȶ��ˣ��ֳ�����һ��С·����ɽ���Ϻ���
����һЩʲô�ּ�(pattern)���ߵ�����������·�ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "east" : __FILE__,
                "west" : __DIR__"xiaolu7",
                "north" : __DIR__"xiaolu4",
                "south" : __FILE__,
        ]));
        set("item_desc",([
          "pattern" : (:l_pattern():),
        ]));
        set("no_clean_up", 0);

        setup();
        //replace_program(ROOM);
}

string l_pattern()
{
        object me=this_player();
        if(me->query_temp("tmark/ָ")==3) {
                me->add_temp("tmark/ָ",1);
                return("�����Ǳ����ô������ָ��֮��Ĺ�����ɽʯ�Ͽ���һ��ʫ����
�˵�ָ�������˵á�\n");
        }
        else {
                me->set_temp("tmark/ָ",0);
                return("ɽ���Ͽ���һ��ʫ����֪������ô����ȥ�ġ�\n");
        }
}
