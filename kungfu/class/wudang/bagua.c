// bagua.c ���Ե���

#include <command.h>
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���Ե���", ( {"bagua dizi","dizi","bagu" }));
        set("age", 23);
        set("gender", "����");
        set("long",
"���佣����Է�λ���ӡ�\n");
        set("attitude", "peaceful");

        set("str", 24);
        set("dex", 16);
        set("combat_exp", 80000);
        set("shen_type", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("sword", 80);
        set_skill("force", 60);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 80);
        set("chat_chance", 5);
        set("chat_msg", ({
                "���Ե�������ߺ�ȣ����佣�����µ�һ��\n",
        }));
        create_family("�䵱��", 3, "����");

        setup();
        carry_object("/clone/weapon/changjian");
        carry_object("/d/wudang/obj/baguafu")->wear();
}
