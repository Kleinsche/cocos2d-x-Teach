//
//  ImageFadeOut.hpp
//  Particle
//
//  Created by Kleinsche on 2017/7/5.
//
//

#ifndef ImageFadeOut_hpp
#define ImageFadeOut_hpp

#include <stdio.h>
#include <cocos2d.h>

USING_NS_CC;

class ImageFadeOut:public Node {
protected:
    ClippingNode* _displayImage;
    DrawNode* _displayClipping;
    
    Image* _image;
    
    //两个运动的点
    int _pointA;
    int _pointB;
    
public:
    ImageFadeOut();
    virtual ~ImageFadeOut();
    static ImageFadeOut* create(std::string image);
    
    
    bool initWithImage(std::string image);
    virtual void update(float d);
};

#endif /* ImageFadeOut_hpp */
