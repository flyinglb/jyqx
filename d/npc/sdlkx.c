/*[1;36mLast modified by һ���(sdlkx) on Sun Apr 15 16:56:52 2001[2;37;0m*/
//jyqxII ������
// by sdlkx 4/15/2001
#include <ansi.h>
inherit NPC;
void create()
{
set_name(HIW"һ���"NOR,({"Sdlkx"}));
set("per",30);
set("nickname",BLINK+HIG"��"HIR"��"HIW"��"HIY"��"NOR);
set("gender", "����");
set("age", 20);
set("long",
     "������������´������������£�һ�����ڲ����ߵ�����\n"+
     "׼�����������˽�������Ǯ��Ҳ����������˵�Ǯ��Ҳ����\n"+
     "�����˳�----"BLINK+HIG"��"HIR"��"HIW"��"HIY"��"NOR"��\n"
);
setup();
carry_object("/d/city2/obj/jinduan")->wear();
}
