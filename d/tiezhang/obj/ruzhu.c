// ruzhu.c ƬƤ����

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "ƬƤ����" NOR, ({"ruzhu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ɫ��ϸ�ۣ�����ζ�ʣ�Դ�ڶ��������ڶ�����
������Ϊ���������ö����Լ����������ļ������͡�\n");
		set("unit", "ֻ");
		set("value", 300);
		set("food_remaining", 5);
		set("food_supply", 100);
	}
}
