inherit ROOM;

void create()
{
        set("short", "����");
        set("long",@LONG
�������������´���ǰ��ֻ�����ƻֺ�������������Ͽ���һ������
( duilian )�����Ḳ�֣����е㲦����֮�⡣̧ͷ�����������һ���
ľ���ң����⡰��ʥ�¡��������֣�������ɡ�������ʽ�������������
�Խй��ˣ�����֮Ϊ�������¡���
LONG );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"talin",
                "north" : "/d/dali/hongsheng",
        ]));
	set("item_desc",([
		"duilian" : "\n    ������Ⱦ����Բ�ɡ�������Ե�������\n\n",
	]));	
        set("objects",([
                "/d/wudang/npc/guest" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
