// /d/xiakedao/duchuan.c
#include <ansi.h>
inherit ROOM;
 
void create()
{
        set("short", "С��");
        set("long",@LONG
����һֻ���߼�����С�ۣ����˴�β�����Ļ������͵����͵�
���⣬�ٲ��������������ˡ����漸���ʹ���ƽ�롣����ûʲô��
�ˣ������������ҡ�
LONG);   
        set("outdoors", "xiakedao");
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM) ;
}
