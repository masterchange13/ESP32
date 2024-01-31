package com.mao.esp32_java_web.Service.ServiceImpl;

import com.mao.esp32_java_web.Service.PageService;
import org.springframework.stereotype.Service;

@Service
public class PageServiceImpl implements PageService {

    @Override
    public String test() {
        return "this is java data, you make it!";
    }
}
