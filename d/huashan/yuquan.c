// yuquan.c

inherit ROOM;

void create()
{
        set("short", "��ȪԺ");
        set("long", @LONG
�������ݺ����Ȫ�����������δ���ϣ�����ӵĵط�����Χ����ʮ��
������٣�ز�ö��ˣ�֦���пգ�����������ƣ��ഫ��ϣ������������
����ֲ��Ժ��������գ�Ȫʯ�续����ˮ�ӻأ��������ۡ�Ժ������Ȫһ
�ɣ�Ȫˮ����������ɽ������������ͨ��������Ȫ����ȪԺ��˵�����
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "south" : __DIR__"path1",
        ]));
//        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/teller": 1
        ]) );

        setup();
        replace_program(ROOM);
}
 
