// yuzhengong.c ���湬
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "���湬");
        set("long", @LONG
��������������ǰ�ľ�ַ���������������˲�����֮ǰ���޵�
�ط��������ִ�ȫ��̺󣬴˵صĲ���ʵ��̫С���ͽ�������Ǩ����
��ɽ�ϣ����˵����¸���Ϊ���湬���Լ���õ�֮�⡣����ܾ�û��
�������ˣ������϶������˻ҳ���
LONG
        );
        set("exits", ([
                "south" : __DIR__"fangzhenqiao",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
