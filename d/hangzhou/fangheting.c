// fangheting.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ź�ͤ");
        set("long", @LONG
ͤ����������÷����һ����ĩ������÷��ʢ�ţ�εȻ�ɹۡ���ͤ
��Ϊ�˼��������ʫ���ֺ;����������ᰮ÷��������Ӱ��бˮ��
ǳ�����㸡���»ƻ衱��������ӽ÷���䡣�ݴ�˵��ʫ�˻�����һֻ��
ȡ������������ÿ���Լ����ɢ����ǡ�п�������ʱ��ͯ�ӾͿ�����
�ף�ʫ�˼��ף���ؼҽӿͣ��������С�÷�޺��ӡ��Ĺ��¡�������
�߱���ƽ�����¡����ϱ����ǹ�ɽ��
LONG);
        set("exits", ([
            "southwest" : __DIR__"gushan",
            "southeast" : __DIR__"pinghuqiuyue",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hangzhou");
        setup();
        replace_program(ROOM);
}
