// dating.c
// written by tree

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�㲽�������ӭ���ǽ�Ϲ���һ��ľ�ң�����д�š�佻�ׯ����ԭ�����Ѿ���
��佻���Ժ�������з������ź�ľ�Σ��Ա߻�վ�ż���СѾ�ߡ������Ų������
������Ϣ���е�ֻ�ǰ��꣬������  
LONG);

       set("exits", ([
               "south" : __DIR__"xiaoyuan",
               "east" : __DIR__"huayuan1",
               "west" : __DIR__"huayuan2",
               "north" : __DIR__"shufang",
]));
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);	
}
