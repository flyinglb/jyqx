inherit ROOM;

void create()
{
        set("short", "������");
        set("long",@LONG
����������������ߵ�һ������Լ������ߣ�����ʮ�������ഫ����
ԭ��������һ��ǰ����ɮ�������ӣ����ڵ���鳼������߱�ϵµ۴�λ��
�����´���ʱ�������Ӳ�֪�����ʧ���ˣ���Ҳ��Ϊ�������������ֵ���
�����¡��������Ҳ��֪�����Ǽ١�
LONG
        );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"baodian",
		"east" : __DIR__"wuwoge",
		"west" : __DIR__"wujingge",
                "north" : __DIR__"talin",
//		"up" :__DIR__"floor1",
        ]));
	set("objects",([
                __DIR__"npc/hutaseng1" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
