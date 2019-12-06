//setwmsg.c
// SetWeaponMsg
//Creat by ZCooker 97.12.6

#include <ansi.h>

inherit F_CLEAN_UP;

string creat_info(string msg1,int flag);
//flag is a variable to say which should be returned
int help();
int main(object me, string info)
{
        string msg,command,msg1;
        object weapon;
        if( !info ) return help();
        if (strsrch(info, "$N") < 0)
                return notify_fail("������Ҫ��$N��ʾ���Լ���\n");
        if (strsrch(info, "$WEAPON$") < 0)
                return notify_fail("������Ҫ��$WEAPON$��ʾ��ı�����\n");
        if (strsrch(info, "��") > 0)
                return notify_fail("����������˷Ƿ��ַ���\n");
        if (strsrch(info, "��") > 0)
                return notify_fail("����������˷Ƿ��ַ���\n");
        if (strsrch(info, "����") > 0)
                return notify_fail("����������˷Ƿ��ַ���\n");
        if (strsrch(info, "���") > 0)
                return notify_fail("����������˷Ƿ��ַ���\n");
        if (strsrch(info, "��ʦ") > 0)
                return notify_fail("����������˷Ƿ��ַ���\n");
        if (strsrch(info, "����") > 0)
                return notify_fail("����������˷Ƿ��ַ���\n");
        if (strsrch(info, "����") > 0)
                return notify_fail("����������˷Ƿ��ַ���\n");
        if (strsrch(info, "�ش�") > 0)
                return notify_fail("����������˷Ƿ��ַ���\n");
        if( !(me->query("weapon/make")))
                return notify_fail("��û�����Ƶı�����\n");
        weapon = present( (me->query("weapon/id")), me );
        if( !objectp(weapon))
                return notify_fail("��ı���������ߣ�\n");
        sscanf(info ,"%s %s" ,command ,msg1);
        switch(command)
        {
                case "-w":
                        msg = creat_info(msg1,1);
                        me->set("weapon/wield_msg",msg+NOR);
                        weapon->set("wield_msg",msg+NOR+"\n");
                        break;
                case "-u":
                        msg = creat_info(msg1,1);
                        me->set("weapon/unwield_msg",msg+NOR);
                        weapon->set("unwield_msg",msg+NOR+"\n");
                        break;
                default :
                        return notify_fail("��������ʧ�ܣ���ѡ������������ϸ�뿴�����ļ���\n");
        }
        write("Ok.\n");
        return 1;
}

string creat_info(string msg1,int flag)
{
        string w_name,name;
        int w_lv,color;
        w_lv = this_player()->query("weapon/lv");
        w_name = this_player()->query("weapon/name");
        color = (w_lv/10);
        color = w_lv - color*10;
        switch(color){
                case 1:
                case 2:
                        name = HIR + w_name + NOR;
                        break;
                case 3:
                case 4:
                        name = HIG + w_name + NOR;
                        break;
                case 5:
                case 6:
                        name = HIY + w_name + NOR;
                        break;
                case 7:
                case 8:
                        name = HIB + w_name + NOR;
                        break;
                case 9:
                        name = HIM + w_name + NOR;
                        break;
                case 0:
                        name = HIC + w_name + NOR;
                        break;
        }
        if ( flag==2 )
                return name;
        msg1 = replace_string(msg1, "$WEAPON$",name);
        msg1 = replace_string(msg1, "$BLK$", BLK);
        msg1 = replace_string(msg1, "$RED$", RED);
        msg1 = replace_string(msg1, "$GRN$", GRN);
        msg1 = replace_string(msg1, "$YEL$", YEL);
        msg1 = replace_string(msg1, "$BLU$", BLU);
        msg1 = replace_string(msg1, "$MAG$", MAG);
        msg1 = replace_string(msg1, "$CYN$", CYN);
        msg1 = replace_string(msg1, "$WHT$", WHT);
        msg1 = replace_string(msg1, "$HIR$", HIR);
        msg1 = replace_string(msg1, "$HIG$", HIG);
        msg1 = replace_string(msg1, "$HIY$", HIY);
        msg1 = replace_string(msg1, "$HIB$", HIB);
        msg1 = replace_string(msg1, "$HIM$", HIM);
        msg1 = replace_string(msg1, "$HIC$", HIC);
        msg1 = replace_string(msg1, "$HIW$", HIW);
        msg1 = replace_string(msg1, "$NOR$", NOR);
        if ( flag==1)
                return msg1;

}

int help()
{
        string  f=RED+"��"+NOR;
        write(
"ָ���ʽ : setwmsg -w|-u <��������>\n"
+"\n"
+f+"���ָ���������Ϊ�Լ�����������װ���Լ�ж��ʱ������\n"
+"    ���ԡ�\n"
+"    -w : ������������Ϊ����װ��ʱ���������ԡ�\n"
+"    -u : ������������Ϊж�±���ʱ���������ԡ�\n"
+"\n"
+f+"�����ϣ����������ʹ�� ANSI �Ŀ�����Ԫ�ı���ɫ��\n"
+"    ���������µĿ����ִ���\n"
+"\n"
+"$BLK$ - ��ɫ    $NOR$ - ����ɫ   $RED$ - ��ɫ    $HIR$ - ����ɫ\n"
+"$GRN$ - ��ɫ    $HIG$ - ����ɫ   $YEL$ - ����ɫ  $HIY$ - ��ɫ\n"
+"$BLU$ - ����ɫ  $HIB$ - ��ɫ     $MAG$ - ǳ��ɫ  $HIM$ - �ۺ�ɫ\n"
+"$CYN$ - ����ɫ  $HIC$ - ����ɫ   $WHT$ - ǳ��ɫ  $HIW$ - ��ɫ\n"
+"����ϵͳ�Զ������ִ�β�˼�һ�� $NOR$��\n"
+"\n"
+f+"����д��ʹ��$N�����Լ���ʹ��$WEAPON$����������ơ�\n"
+"\n"
+f+"ע������ڱ������ƺ�����д������ô��Ҫ���¶�����ɫ\n"
+"    ����Ĭ����ɫ����\n"

        );
        return 1;
}
