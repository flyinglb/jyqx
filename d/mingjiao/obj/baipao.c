// baipao.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�ײ�����", ({ "cloth","pao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("unit", "��");
		set("long", 
			"���Ǽ��ײ����ۣ��䲻�ݻ���ȴϴ��һ����Ⱦ�����۽�������һ��Ѫ��Ļ��棬\n"
			"��Ϊ���ޡ�\n");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

