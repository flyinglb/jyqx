// chongyanggate.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "����������");
        set("long", @LONG
�����ߵ�������ɽ��ɽ����ǰ�����ȫ��̵��ܲ��������ˡ���
����ɽ�������ߵʹ������¡���Χ��ľɭɭ��������֣���ɫ���ġ�
��ǰ����ǽ���ߣ��������ݣ�����һ�����������������ߵ����ɼ
ľ��ͭ����(door)���Ϸ�һ����ң����ɷ�������š�������������
���֡������ǹ㳡��
    ȫ�����ݲ����š�
LONG
        );
        set("outdoors", "gumu");
        set("exits", ([
                "southdown"   : __DIR__"daxiaochang",
        ]));

        setup();
        replace_program(ROOM);
}
