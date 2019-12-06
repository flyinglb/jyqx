// edit.c
// modified by wind

inherit F_CLEAN_UP;

int main(object me, string file)
{
        if( !file ) return notify_fail("Ö¸Áî¸ñÊ½£ºedit <µµÃû>\n");
        if( in_edit(me) ) return notify_fail("ÄãÒÑ¾­ÔÚÊ¹ÓÃ±à¼­Æ÷ÁË¡£\n");
        
        file = resolve_path(me->query("cwd"), file);
        
        seteuid(geteuid(me));
        
        if (!(int)SECURITY_D->valid_write(file, me, "write_file"))
                return notify_fail("±à¼­´íÎó£ºÎÞÐ§µÄÎÄ¼þÃû¡£\n");
        
        log_file("edit/"+geteuid(me), sprintf("edit %s %s\n", file, ctime(time())) );

        ed(resolve_path(me->query("cwd"), file));
        return 1;
}

int help(object me)
{
  write(@HELP
Ö¸Áî¸ñÊ½ : edit <µµÃû>, edit here
ÀûÓÃ´ËÒ»Ö¸Áî¿ÉÖ±½ÓÔÚÏßÉÏ±à¼­µµ°¸¡£
                /ÏòÇ°ËÑË÷Æ¥ÅäÏî
                ?ÏòºóËÑË÷Æ¥ÅäÏî
                =ÏÔÊ¾µ±Ç°ËùÔÚÐÐÊý
                aÔÚµ±Ç°ÐÐµÄºóÃæÌí¼Ó
                AÓë'a'ÏàËÆ
                cÐÞ¸Äµ±Ç°ÐÐ£¬Ìæ»»²éÑ¯ÎÄ±¾
                dÉ¾³ýÒ»ÐÐ»ò¶àÐÐ
                eÓÃÁíÒ»¸öÎÄ¼þ¸²¸Çµ±Ç°ÎÄ¼þ
                EÓë'e'ÏàËÆ£¬µ«Ö»ÔÚÎÄ¼þ±»×ÓÐÞ¸ÄÖ®ºóÓÐÐ§
                fÏÔÊ¾/¸Ä±äµ±Ç°ÎÄ¼þµÄÎÄ¼þÃû
                gËÑË÷²¢¶ÔÆ¥ÅäµÄÐÐÖ´ÐÐÄ³ÖÖÃüÁî
                h°ïÖú
                iÔÚµ±Ç°ÐÐÇ°²åÈë×Ö·û
                kÓÃÒ»¸ö×Ö·û±ê¼Çµ±Ç°ÐÐ
                lÁÐ³öÒ»ÐÐ»ò¶àÐÐ£¨´ø¿ØÖÆ×Ö·û£©
                mÒÆ¶¯Ò»ÐÐ»ò¶àÐÐµ½Ö¸¶¨µÄÎ»ÖÃ£¨ÐÐºÅ£©
                n±ê¼ÇÐÐºÅ
                OÍ¬'i'
                oÍ¬ 'a'
                pÁÐ³öÒ»¶¨·¶Î§µÄÐÐ
                qÍË³ö
                QÍË³ö£¬¶øÇÒ²»´æ
                rÔÚÎÄ¼þÎ²²¿»òÖ¸¶¨ÐÐºó¶ÁÈëÆäËüÎÄ¼þ
                sËÑË÷²¢Ìæ»»
                set²éÑ¯¡¢¸Ä±ä»ò´æ´¢Ä³ÖÖÉè¶¨Ñ¡Ïî
                t¿½±´Ò»ÐÐ»ò¼¸ÐÐµ½Ö¸¶¨ÐÐÊý
                vËÑË÷²¢¶Ô²»Æ¥ÅäµÄÐÐÖ´ÐÐÄ³ÖÖÃüÁî
                x´æÎÄ¼þ²¢ÍË³ö
                wÐ´Èëµ±Ç°ÎÄ¼þ£¨»òÖ¸¶¨ÎÄ¼þ£©²ÉÓÃ¸²¸Ç³)
                WÏÖ'w'ÏàËÆ£¬²ÉÓÃ×·¼Ó
                zÏÔÊ¾20ÐÐ£¬¿ÉÓÃ . + - ÈýÖÖ±ê¼Ç
                ZÏÔÊ¾40ÐÐ£¬¿ÉÓÃ . + - ÈýÖÖ±ê¼Ç

HELP
    );
    return 1;
}

