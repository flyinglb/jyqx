//npc.c ����ʹ��

inherit NPC;
#include <ansi.h>

void create()
{
        set_name(HIY "С��ͯ" NOR, ({ "Xiao WanTong", "Xiao" }) );
        set("gender", "����" );
        set("age", 16);
        set("long", "��������Զ����һ���ɰ���Ц����\n");
        set("per", 28);
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set_skill("unarmed", 50);
        set_skill("parry", 70);
        set("max_neili", 9999999);
        set("max_qi", 9999999);
        set("eff_neili", 9999999);
        set("neili", 9999999);
        set("eff_qi", 9999999);
        set("qi", 9999999);
        set("max_jingli", 9999999);
        set("jingli", 9999999);
        set("max_jing", 9999999);
        set("eff_jing", 9999999);
        set("jing", 9999999);

        set("chat_chance", 3);
        set("chat_msg", ({
                (: command("es ���½�ӹȺ����II��host:61.156.17.111 port:1999 ��ӭ���ĵ�����") :),
                (: command("es ���½�ӹȺ����II��host:61.156.17.111 port:1999 ��ӭ���ĵ�����") :),
                (: command("es ���½�ӹȺ����II��host:61.156.17.111 port:1999 ��ӭ���ĵ�����") :),
                (: command("es ���½�ӹȺ����II��host:61.156.17.111 port:1999 ��ӭ���ĵ�����") :),
                (: command("es ���½�ӹȺ����II��host:61.156.17.111 port:1999 ��ӭ���ĵ�����") :),
                (: command("chat �����ע��͵����԰����ʦ����壡����") :),
                (: command("chat ��ӭ���ȥ��ʦ����� post BUG �� ���ǻᾡ������") :),
                (: command("chat* yawn Xiao") :),
        }) );
        setup();
}
