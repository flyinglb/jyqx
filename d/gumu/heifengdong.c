// heifengdong.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�ڷﶴ");
        set("long", @LONG
�˴�λ�����ɽ��������̫��ɽ�ϡ�ֻ��ɽ��ֱ��ֱ�£�����
��Ķ��ͣ�ֻɽ������һ�������Ӵֵ�ʯ������ʱð��һ�ɺ�������
���µġ�������һƬ���֡�
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "westup"  : __DIR__"shulin7",
        ]));

        setup();
        replace_program(ROOM);
}
